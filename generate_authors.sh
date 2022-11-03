#!/usr/bin/env bash
set -e

{
	cat <<-'EOF'

# This file lists the names of individuals who contributed to this project
EOH
echo
git log --format='%aN <%aE>' | LC_ALL=C.UTF-8 sort -uf
} > AUTHORS
