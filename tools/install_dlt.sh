#!/usr/bin/env bash

set -e

sudo find /usr/local/ -name "*dlt*" -delete


echo "Installing DLT..."

BUILD_DIR=$(dirname "$0")/../build

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
if [ ! -f /etc/dlt.conf ]; then
    sudo cp ${BUILD_DIR}/_deps/dlt-src/src/daemon/dlt.conf /etc/dlt.conf
fi

echo "6. Clear any existing DLT daemon processes..."
sudo systemctl stop dlt 2>/dev/null || true
sudo pkill -9 dlt-daemon || true
sudo rm -f /tmp/dlt
sudo rm -f /tmp/dlt_fifo

echo "7. Register DLT daemon in systemd..."
SERVICE_FILE="/etc/systemd/system/dlt.service"
if [ ! -f ${SERVICE_FILE} ]; then
    echo "Creating systemd service file for DLT..."
    sudo bash -c "cat > $SERVICE_FILE" <<EOF
[Unit]
Description=Automotive Diagnostic Log and Trace
After=network.target

[Service]
Type=simple
ExecStart=/usr/local/bin/dlt-daemon
Restart=always
User=root

[Install]
WantedBy=multi-user.target
EOF
fi

echo "8. Enable and start DLT daemon..."
sudo systemctl daemon-reload
sudo systemctl enable dlt
sudo systemctl start dlt

echo "9. Verify DLT daemon status..."
sleep 1
if systemctl is-active --quiet dlt; then
    echo "DLT Daemon running success!"
    systemctl status dlt --no-pager
else
    echo "Error during start daemon. Check logs: journalctl -u dlt"
fi

echo "DLT is installed and running."