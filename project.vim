" Write buffers, determine target in Makefile, run make <target> and execute
" the compiled program.
map <Leader>t :wall!\|:let make_target=expand('%:t:r')\|:execute ":make " . make_target\|:execute ":!./" . make_target . ".o"<cr>
