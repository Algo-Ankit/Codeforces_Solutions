#!/bin/bash

# Ask for custom message
echo "📦 Enter commit message:"
read msg

# Format the date
today=$(date +"%Y-%m-%d")

# Git operations
git add .
git commit -m "📅 $today: $msg"
git push origin main
