for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int x = BOARD_X + j * CELL_SIZE;
            int y = BOARD_Y + i * CELL_SIZE;
            switch (game.board[i][j]) {
                case EMPTY_CELL: renderTextureResizeImage(cellEmpty, &destRect);
                break;
                case X_CELL: renderTextureResizeImage(cellX, &destRect);
                break;
                case O_CELL: renderTextureResizeImage(cellO, &destRect);
                break;
            };

        };
    }
