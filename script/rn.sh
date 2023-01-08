#!/usr/bin/env bash

arquivo="$1"

while IFS= read -r linha || [[ -n "$linha" ]]; do
  echo "$linha"
done < "$arquivo"

