

			// 변수 지정
			var nextBtn = document.querySelector(".slide_next_btn");
			var prevBtn = document.querySelector(".slide_prev_btn");
			var slide_back = document.querySelector(".slide_item");
			var slide_url = document.querySelectorAll(".elementor-carousel-image");
			var modalClose = document.querySelector(".slide_box");
			var modals = document.querySelector(".sub_slide");
			var openModal = document.querySelector(".swiper-wrapper");
			
			console.log(slide_url);
			
			// 함수 

			function modalsOpen(){
				modals.style.display = "block";

				slide_back.style.backgroundImage = slide_url[1].style.backgroundImage;
			};

			function modalsClose(){
				modals.style.display = "none";
			}

			

			var count = 1;

			function nextSlide(){

				if(count >= 5) {
					count=1;
				}else{
					count++;
				}

				slide_back.style.backgroundImage = slide_url[count].style.backgroundImage;
				slide_back.style.backgroundSize = "cover";

			}

			function prevSlide(){

				if(count <= 1) {
					count=5;
				}else{
					count--;
				}

				slide_back.style.backgroundImage = slide_url[count].style.backgroundImage;
				slide_back.style.backgroundSize = "cover";

			}


			// 함수 실행

			openModal.addEventListener("click",modalsOpen);
			modalClose.addEventListener("click",modalsClose);
			nextBtn.addEventListener("click", nextSlide);
			prevBtn.addEventListener("click",prevSlide);
	