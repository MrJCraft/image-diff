#include<stdio.h>
#include<stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

#include "base/base_inc.h"

#include <emmintrin.h>
#include <omp.h>


typedef struct {
      U32 width;
      U32 height; 
      U32 channels;
      Color32* data;
} Image;


void image_diff(char* name1, char* name2) {

      Image img1;
      img1.width = 0;
      img1.height = 0;
      img1.channels = 0;
      img1.data = (Color32*) stbi_load(name1, &img1.width,&img1.height,&img1.channels,4);
    
      Image img2;
      img2.width = 0;
      img2.height = 0;
      img2.channels = 0;
      img2.data = (Color32*) stbi_load(name2, &img2.width,&img2.height,&img2.channels,4);
    
      if(img1.width != img2.width || img1.height != img2.height) {
            printf("Images must be the same size");
            return;
      }
      U32 width = img1.width;
      U32 height = img1.height;
      U32 channels = img1.channels;

      const U32 vector_size = 4;
      const U32 total_elements = width*height;
      #pragma omp parallel for
      for (U32 i = 0; i <= total_elements; i += vector_size) {
            __m128i img1_vec = _mm_loadu_si128((__m128i*)&img1.data[i]);
            __m128i img2_vec = _mm_loadu_si128((__m128i*)&img2.data[i]);
            __m128i result_vec = _mm_sub_epi32(img2_vec, img1_vec);
            _mm_storeu_si128((__m128i*)&img1.data[i], result_vec);
      }
      
      for (U32 i = ((total_elements/vector_size)*vector_size); i < total_elements; ++i) {
            img1.data[i].value = img2.data[i].value - img1.data[i].value;
      }
    
      int success = stbi_write_png("diff.png", img1.width, img1.height, img1.channels, (U8*) img1.data, img1.width * img1.channels);
    
}


int main(int argc, char* argv[]) {
      image_diff(argv[1], argv[2]);
      return 0;
}


