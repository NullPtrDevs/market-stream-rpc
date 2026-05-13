#!/usr/bin/env bash

set -e

sudo find /usr/local/ -name "*dlt*" -delete


echo "Installing DLT..."

SCRIPT_DIR=$(dirname "$0")
BUILD_DIR=${SCRIPT_DIR}/../build
DLT_FIFO_GROUP=$(id -gn)

if [ -d ${BUILD_DIR} ]; then
    rm -rf ${BUILD_DIR}
fi

echo "1. Configuring DLT..."
cmake -B ${BUILD_DIR} -G Ninja -DCMAKE_BUILD_TYPE=Release

echo "2. Building DLT..."
cmake --build ${BUILD_DIR}

echo "3. Installing DLT..."
sudo cmake --install ${BUILD_DIR}

echo "4. DLT installation complete. Update ldconfig..."
sudo ldconfig

echo "5. Prepare DLT config and start DLT daemon..."
sudo cp /usr/local/etc/dlt.conf /etc/dlt.conf
sudo sed -i "s/^# DaemonFifoGroup = .*/DaemonFifoGroup = ${DLT_FIFO_GROUP}/" /etc/dlt.conf

echo "6. Clear any existing DLT daemon processes..."
sudo systemctl stop dlt 2>/dev/null || true
sudo pkill -9 dlt-daemon || true
sudo rm -rf /tmp/dlt
sudo rm -f /tmp/dlt_fifo

echo "7. Register DLT daemon in systemd..."
SERVICE_FILE="/etc/systemd/system/dlt.service"
echo "Creating systemd service file for DLT..."
sudo bash -c "cat > $SERVICE_FILE" <<EOF
[Unit]
Description=Automotive Diagnostic Log and Trace
After=network.target

[Service]
Type=simple
ExecStart=/usr/local/bin/dlt-daemon -x 2 -c /etc/dlt.conf
Restart=always
User=root

[Install]
WantedBy=multi-user.target
EOF

echo "8. Enable and start DLT daemon..."
sudo systemctl daemon-reload
sudo systemctl enable dlt
sudo systemctl restart dlt

echo "9. Verify DLT daemon status..."
sleep 1
if systemctl is-active --quiet dlt; then
    echo "DLT Daemon running success!"
    systemctl status dlt --no-pager
    pgrep -a dlt-daemon || true
else
    echo "Error during start daemon. Check logs: journalctl -u dlt"
fi

echo "DLT is installed and running."