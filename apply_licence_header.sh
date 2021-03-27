for f in $(find src -name "*.c"); do
    echo "$(echo "// SPDX-License-Identifier: GPL-3.0-or-later") $(echo "// Copyright (C) 2021 TTG <prs.ttg+projectname@pm.me>") $(cat $f)" > test.c
done