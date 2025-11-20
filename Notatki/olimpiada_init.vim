" ─────────────────────────────
" Podstawowe opcje
set nocompatible        " wyłącza stary vi
syntax on               " kolorowanie składni
filetype plugin indent on  " automatyczne wcięcia wg języka
set number              " numerki linii
set ignorecase          " wyszukiwanie ignoruje wielkość liter
set incsearch           " wyszukiwanie "na żywo"
set hlsearch            " podświetla wszystkie wyniki
set showmatch           " podświetla pasujące nawiasy
set autoindent          " kopiuj wcięcie nowej linii
set tabstop=4           " tab = 4 spacje
set shiftwidth=4        " automatyczne wcięcie = 4 spacje
set expandtab           " zamieniaj taby na spacje
set noswapfile          " brak swapów (szybsze)
set cursorline          " podświetl bieżącą linię
set ttyfast             " przyspiesza scrollowanie w terminalu
" ─────────────────────────────
" Kopiowanie do systemowego schowka (jeśli +clipboard)
set clipboard=unnamedplus
" ─────────────────────────────
" Szybkie remapy (opcjonalnie do pamięci)
nnoremap o o            " nowa linia pod aktualną + insert
nnoremap O O            " nowa linia nad aktualną + insert
nnoremap dd dd          " usuń linię
nnoremap dw dw          " usuń słowo
nnoremap p p            " wklej
nnoremap y y            " yank (kopiuj)
" podstawowe dawanie zakonczenia nawiasu itp
inoremap [ []<Left>
inoremap ( ()<left>
inoremap { {}<Left>
inoremap " ""<Left>
inoremap ' ''<Left>
" newline po {
" inoremap {<CR> {<CR><C-o>O}
" inoremap {<CR> {<CR>}<Esc>O
" Insert mode: Enter po { tworzy nowy blok
" inoremap <expr> { (getline('.')[col('.')-1] != '{') ? '{' : "{\n\<Esc>O"


