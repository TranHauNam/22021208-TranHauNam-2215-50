- Cài đặt thư viện SDL2
1. Download SDL2-devel-2.28.5-mingw.zip từ https://github.com/libsdl-org/SDL/releases/tag/release-2.28.5 sau đó mình gỡ nén
2. Mình sẽ sử dụng thư mục ...\x86_64-w64-mingw32. Lưu ý: không sử dụng thư mục ...\i686-w64-mingw32
3. Copy file dll vào thư mục mã nguồn project (nơi có các file .cpp)
...\x86_64-w64-mingw32\bin\SDL2.dll 
4. Setting | Compiler | Linker Setting: chép vào Other Linker Option:
-lmingw32 -lSDL2main -lSDL2
5. Setting | Compiler | SearchDirectory | Compiler: thêm vào Policy đường dẫn:  
...\x86_64-w64-mingw32\include\SDL2 
6. Setting | Compiler | SearchDirectory | Linker: thêm vào Policy đường dẫn:  
...\x86_64-w64-mingw32\lib
   
- Cài đặt thư viện SDL2_image
1. Download SDL2_image-devel-2.8.2-mingw.zip từ https://github.com/libsdl-org/SDL_image/releases sau đó mình gỡ nén
2. Mình sẽ sử dụng thư mục ...\x86_64-w64-mingw32. Lưu ý: không sử dụng thư mục ...\i686-w64-mingw32
3. Copy vào thư mục mã nguồn project (nơi có các file .cpp và SDL2.dll lần trước)
...\SDL2_image-2.8.2x86_64-w64-mingw32\bin\SDL2_image.dll 
4. Setting | Compiler | Linker Setting: chép thêm vào Other Linker Option:
-lSDL2_image
5. Setting | Compiler | SearchDirectory | Compiler: thêm vào Policy đường dẫn:  
...\SDL2_image-2.8.2\x86_64-w64-mingw32\include\SDL2 
6. Setting | Compiler | SearchDirectory | Linker: thêm vào Policy đường dẫn:  
...\SDL2_image-2.8.2\x86_64-w64-mingw32\lib
   
- Cài đặt thư viện SDL2_mixer
1. Download SDL2_mixer-devel-2.8.0-mingw.zip từ https://github.com/libsdl-org/SDL_mixer/releases và gỡ nén
2. Mình sẽ sử dụng thư mục ...\x86_64-w64-mingw32. Lưu ý: không sử dụng thư mục ...\i686-w64-mingw32
3. Copy vào thư mục mã nguồn project (nơi có các file .cpp và SDL2.dll lần trước)
...\SDL2_mixer-2.8.0\x86_64-w64-mingw32\bin\SDL2_mixer.dll
4. Setting | Compiler | Linker Setting: chép thêm vào Other Linker Option:
-lSDL2_mixer
5. Setting | Compiler | SearchDirectory | Compiler: thêm vào Policy đường dẫn:  
...\SDL2_mixer-2.8.0\x86_64-w64-mingw32\include\SDL2
6. Setting | Compiler | SearchDirectory | Linker: thêm vào Policy đường dẫn:  
...\SDL2_mixer-2.8.0\x86_64-w64-mingw32\lib
   
- Cài đặt thư viện SDL2_ttf
1. Download SDL2_ttf-devel-2.22.0-mingw.zip từ https://github.com/libsdl-org/SDL_ttf/releases và gỡ nén
2. Mình sẽ sử dụng thư mục ...\x86_64-w64-mingw32. Lưu ý: không sử dụng thư mục ...\i686-w64-mingw32
3. Copy vào thư mục mã nguồn project (nơi có các file .cpp và SDL2.dll lần trước)
...\SDL2_ttf-2.22.0\x86_64-w64-mingw32\bin\SDL2_ttf.dll
4. Setting | Compiler | Linker Setting: chép thêm vào Other Linker Option:
-lSDL2_ttf
5. Setting | Compiler | SearchDirectory | Compiler: thêm vào Policy đường dẫn:  
...\SDL2_ttf-2.22.0\x86_64-w64-mingw32\include\SDL2
6. Setting | Compiler | SearchDirectory | Linker: thêm vào Policy đường dẫn:  
...\SDL2_ttf-2.22.0\x86_64-w64-mingw32\lib
