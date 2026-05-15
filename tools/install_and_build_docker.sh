#!/usr/bin/env bash
set -euo pipefail

# install_and_build_docker.sh
# Checks if Docker is installed and if not: installs it, creates docker group,
# adds a user to the group and ensures socket permissions.

USER_TO_ADD="${1:-$(whoami)}"

echo "User to add to docker group: $USER_TO_ADD"

command -v docker >/dev/null 2>&1 && {
  echo "Docker is already installed: $(docker --version)"
  echo "Ensuring user "$USER_TO_ADD" is in docker group..."
  sudo groupadd -f docker || true
  sudo usermod -aG docker "$USER_TO_ADD" || true
  sudo chmod 660 /var/run/docker.sock || true
  echo "Done. You may need to re-login for group changes to take effect."
  exit 0
}

echo "Docker not found. Attempting installation..."

install_docker_apt() {
  sudo apt-get update
  sudo apt-get install -y ca-certificates curl gnupg lsb-release
  sudo mkdir -p /etc/apt/keyrings
  curl -fsSL https://download.docker.com/linux/$(. /etc/os-release && echo "$ID")/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
  echo \
    "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/$(. /etc/os-release && echo "$ID") \
    $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
  sudo apt-get update
  sudo apt-get install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
}

install_docker_apt

echo "Enabling and starting docker service..."
sudo systemctl enable --now docker || true

echo "Creating docker group and adding user..."
sudo groupadd -f docker || true
sudo usermod -aG docker "$USER_TO_ADD" || true
sudo chmod 660 /var/run/docker.sock || true

echo "Docker installed: $(docker --version)"
echo "User $USER_TO_ADD added to docker group. Re-login may be required."

echo "Building docker image from docker/ci-container.Dockerfile..."
docker build -f docker/ci-container.Dockerfile -t ci-container .

exit 0
