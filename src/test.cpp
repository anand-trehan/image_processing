#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include<vector>
using namespace std;

struct image{
	int rows;
	int columns;
	int height;
	vector<vector<int> >R;
	vector<vector<int> >G;
	vector<vector<int> >B;
};

image initialise_0(image im1){
	int r,c,h;
 	r=im1.rows;
 	c=im1.columns;
 	h=im1.height;
 	vector<vector<int> >R1(r);
	vector<vector<int> >G1(r);
	vector<vector<int> >B1(r);
	for(int i=0;i<r;++i){
 		vector<int>temp(c);
 		R1[i]=temp;
 		G1[i]=temp;
 		B1[i]=temp;
 	}

 	for(int i=0;i<c;++i){
 		for(int j=0;j<r;++j){
 			R1[j][i]=0;
 		}
 	}

 	for(int i=0;i<c;++i){
 		for(int j=0;j<r;++j){
 			G1[j][i]=0;
 		}
 	}

 	for(int i=0;i<c;++i){
 		for(int j=0;j<r;++j){
 			B1[j][i]=0;
 		}
 	}

 	im1.R=R1;
 	im1.G=G1;
 	im1.B=B1;


 	return im1;

}
/*
image read_image1(){
 	int r,c,h;
 	cin>>r>>c>>h;
 	image im1;
 	im1.rows=r;
 	im1.columns=c;
 	im1.height=h;
 	vector<vector<int> >R1(r);
	vector<vector<int> >G1(r);
	vector<vector<int> >B1(r);
	for(int i=0;i<r;++i){
 		vector<int>temp(c);
 		R1[i]=temp;
 		G1[i]=temp;
 		B1[i]=temp;
 	}

 	for(int i=0;i<r;++i){
 		for(int j=0;j<c;++j){
 			cin>>R1[i][j];
 		}
 	}

 	for(int i=0;i<r;++i){
 		for(int j=0;j<c;++j){
 			cin>>G1[i][j];
 		}
 	}

 	for(int i=0;i<r;++i){
 		for(int j=0;j<c;++j){
 			cin>>B1[i][j];
 		}
 	}

 	im1.R=R1;
 	im1.G=G1;
 	im1.B=B1;


 	return im1;

}
*/

image read_image(){
 	int r,c,h;
 	cin>>r>>c>>h;
 	image im1;
 	im1.rows=r;
 	im1.columns=c;
 	im1.height=h;
 	vector<vector<int> >R1(r);
	vector<vector<int> >G1(r);
	vector<vector<int> >B1(r);
	for(int i=0;i<r;++i){
 		vector<int>temp(c);
 		R1[i]=temp;
 		G1[i]=temp;
 		B1[i]=temp;
 	}

 	for(int i=0;i<c;++i){
 		for(int j=0;j<r;++j){
 			cin>>R1[j][i];
 		}
 	}

 	for(int i=0;i<c;++i){
 		for(int j=0;j<r;++j){
 			cin>>G1[j][i];
 		}
 	}

 	for(int i=0;i<c;++i){
 		for(int j=0;j<r;++j){
 			cin>>B1[j][i];
 		}
 	}

 	im1.R=R1;
 	im1.G=G1;
 	im1.B=B1;


 	return im1;

}

void dump_image(image im1,string filename){
	ofstream myfile;
	myfile.open(filename);
	myfile<<im1.rows<<"\n"<<im1.columns<<"\n"<<im1.height<<endl;
	for(int i=0;i<im1.columns;++i){
 		for(int j=0;j<im1.rows;++j){
 			myfile<<im1.R[j][i]<<endl;
 		}
 	}

 	for(int i=0;i<im1.columns;++i){
 		for(int j=0;j<im1.rows;++j){
 			myfile<<im1.G[j][i]<<endl;
 		}
 	}

 	for(int i=0;i<im1.columns;++i){
 		for(int j=0;j<im1.rows;++j){
 			myfile<<im1.B[j][i]<<endl;
 		}
 	}
 	myfile.close();
 	return;
}


image convert_to_grayscale(image im1){
	image im2;
	im2.rows=im1.rows;
	im2.columns=im1.columns;
	im2.height=im1.height;
	vector<vector<int> >g(im1.rows,vector<int> (im1.columns));
	for(int i=0;i<im1.columns;++i){
 		for(int j=0;j<im1.rows;++j){
 			g[j][i]=(im1.R[j][i]+im1.B[j][i]+im1.G[j][i])/3;
 		}
 	}
 	im2.R=g;
 	im2.G=g;
 	im2.B=g;

 	return im2;
}

image invert_colors(image im1){
	for(int i=0;i<im1.columns;++i){
 		for(int j=0;j<im1.rows;++j){
 			im1.R[j][i]=255-im1.R[j][i];
 			im1.B[j][i]=255-im1.B[j][i];
 			im1.G[j][i]=255-im1.G[j][i];
 		}
 	}
 	return im1;
}

image addimages(image im1,image im2){
	//both im1 and im2 must be of same size
	image newim=im1;

	for (int i = 0; i < im1.rows; i++) {
        for (int j = 0; j < im1.columns; j++) {
            newim.R[i][j]=min(255,im1.R[i][j]+im2.R[i][j]);
            newim.G[i][j]=min(255,im1.G[i][j]+im2.G[i][j]);
            newim.B[i][j]=min(255,im1.B[i][j]+im2.B[i][j]);
		}
	}
	
	return newim;
}

image thresholding(image im1,int threshold){
	for(int i=0;i<im1.rows;++i){
		for(int j=0;j<im1.columns;++j){
			if(im1.R[i][j]<=threshold){
				im1.R[i][j]=0;
			}
			else{
				im1.R[i][j]=255;
			}
		}
	}

	for(int i=0;i<im1.rows;++i){
		for(int j=0;j<im1.columns;++j){
			if(im1.G[i][j]<=threshold){
				im1.G[i][j]=0;
			}
			else{
				im1.G[i][j]=255;
			}
		}
	}

	for(int i=0;i<im1.rows;++i){
		for(int j=0;j<im1.columns;++j){
			if(im1.B[i][j]<=threshold){
				im1.B[i][j]=0;
			}
			else{
				im1.B[i][j]=255;
			}
		}
	}
	return im1;
}


//image must be grayscale
vector<int> compute_histogram(image im1){
	vector<int>hist(256);
	im1=convert_to_grayscale(im1);//can be commented as input is grayscale
	for(int i=0;i<im1.rows;++i){
		for(int j=0;j<im1.columns;++j){
			hist[im1.R[i][j]]++;
		}
	}

	return hist;
}

//input image must be grayscale
image otsu_binarize(image im1){
	im1=convert_to_grayscale(im1);//can be commented as input is grayscale
	vector<int>hist = compute_histogram(im1);
	int total_sum=0;
	for(int i=0;i<256;++i){
		total_sum+=hist[i];
	}
	//convert the histogram counts into probabilities
	vector<double>probabilities(256);
	for(int i=0;i<256;++i){
		probabilities[i]=(double(hist[i])/double(total_sum));
	}
	vector<double>pdf(256);//if threshold is p,it stores probabilities <=p
	vector<double>mean(256);//mean of all pixels <=p
	vector<double>inter_cluster_variance(256);//variance between the two clusters demarcated by p(we need to maximise this)
	pdf[0]=probabilities[0];
	vector<int>count(256);
	count[0]=hist[0];
	for(int i=1;i<256;++i){
		count[i]=count[i-1]+hist[i];
	}

	mean[0]=0;
	for(int i=1;i<256;++i){
		pdf[i]=pdf[i-1]+probabilities[i];
		mean[i]=((mean[i-1]*count[i-1])+(i*hist[i]))/count[i];
	}
	double threshold=0;
	double max_var=0;

	for(int i=0;i<256;++i){

		if(pdf[i]!=0 && pdf[i]!=1){
			inter_cluster_variance[i]=(pow(mean[255]-mean[i],2)/(1-pdf[i]))*pdf[i];
		}
		else{
			inter_cluster_variance[i]=0;
		}

		if(inter_cluster_variance[i]>max_var){
			max_var=inter_cluster_variance[i];
			threshold=i;
		}
	}

	image newim=thresholding(im1,int(threshold));

	return newim;

}

image convolution2D(image im1,vector<vector<int> > kernel,int kernel_size,int norm){
	image opimage;
	//im1=convert_to_grayscale(im1);
	opimage=im1;
	/*opimage.rows=im1.rows;
	opimage.columns=im1.columns;
	opimage.height=im1.height;
	opimage.R=im1.R;
	opimage.G=im1.G;
	opimage.B=im1.B;*/


	int kernel_origin=kernel_size/2;

	for(int i=0;i<im1.rows;++i){
		for(int j=0;j<im1.columns;++j){
			int sumr=0;
			int sumg=0;
			int sumb=0;
			for(int m=0;m<kernel_size;++m){
				int mt=kernel_size-m-1;

				for(int n=0;n<kernel_size;++n){
					int nt=kernel_size-n-1;
					int it=i+(m-kernel_origin);
					int jt=j+(n-kernel_origin);

					/*if (it < 0)
                        it = it + 1;
                    if (jt < 0)
                        jt = jt + 1;
                    if (it >= im1.rows)
                        it = it - 1;
                    if (jt >= im1.columns)
                        jt = jt - 1;*/

					if(it>=0 && jt>=0 && it<im1.rows && jt<im1.columns){
						sumr+=(im1.R[it][jt]*kernel[mt][nt]);
						sumg+=(im1.G[it][jt]*kernel[mt][nt]);
						sumb+=(im1.B[it][jt]*kernel[mt][nt]);
					}
				}
			}

			double valr=sumr/norm;
			if(valr<0){
				valr=0;
			}
			else if(valr>255){
				valr=255;
			}
			opimage.R[i][j]=int(valr);

			double valg=sumg/norm;
			if(valg<0){
				valg=0;
			}
			else if(valg>255){
				valg=255;
			}
			opimage.G[i][j]=int(valg);

			double valb=sumb/norm;
			if(valb<0){
				valb=0;
			}
			else if(valb>255){
				valb=255;
			}
			opimage.B[i][j]=int(valb);
		}
	}

	return opimage;

}

image edge_detection(image im1){
	//vector<vector<int> > kernel{ {-1,-1,-1},{-1,8,-1},{-1,-1,-1} };
	//this is  a laplacian operator
	vector<vector<int> >kernel(3);
	kernel[0].push_back(-1);kernel[0].push_back(-1);kernel[0].push_back(-1);
	kernel[1].push_back(-1);kernel[1].push_back(8);kernel[1].push_back(-1);
	kernel[2].push_back(-1);kernel[2].push_back(-1);kernel[2].push_back(-1);

	image newim=convolution2D(im1,kernel,3,1);
	return convert_to_grayscale(newim);
}

image mean_filter(image im1){
	//vector<vector<int> > kernel{ {-1,-1,-1},{-1,8,-1},{-1,-1,-1} };
	vector<vector<int> >kernel(3);
	kernel[0].push_back(1);kernel[0].push_back(1);kernel[0].push_back(1);
	kernel[1].push_back(1);kernel[1].push_back(1);kernel[1].push_back(1);
	kernel[2].push_back(1);kernel[2].push_back(1);kernel[2].push_back(1);

	image newim=convolution2D(im1,kernel,3,9);
	return newim;
}

image sobel_edge_detector(image im1){
	//vector<vector<int> > kernel{ {-1,-1,-1},{-1,8,-1},{-1,-1,-1} };
	//horizontal component
	vector<vector<int> >kernel1(3);
	kernel1[0].push_back(-1);kernel1[0].push_back(-2);kernel1[0].push_back(-1);
	kernel1[1].push_back(0);kernel1[1].push_back(0);kernel1[1].push_back(0);
	kernel1[2].push_back(1);kernel1[2].push_back(2);kernel1[2].push_back(1);

	//vertical component
	vector<vector<int> >kernel2(3);
	kernel2[0].push_back(-1);kernel2[0].push_back(0);kernel2[0].push_back(1);
	kernel2[1].push_back(-2);kernel2[1].push_back(0);kernel2[1].push_back(2);
	kernel2[2].push_back(-1);kernel2[2].push_back(0);kernel2[2].push_back(1);

	image temp=convolution2D(im1,kernel1,3,1);
	image newim=convolution2D(temp,kernel2,3,1);
	return convert_to_grayscale(newim);
	//check final
}

image gaussian_blur_r3(image im1){
	vector<vector<int> >kernel(3);
	kernel[0].push_back(1);kernel[0].push_back(2);kernel[0].push_back(1);
	kernel[1].push_back(2);kernel[1].push_back(4);kernel[1].push_back(2);
	kernel[2].push_back(1);kernel[2].push_back(2);kernel[2].push_back(1);

	image newim=convolution2D(im1,kernel,3,16);

	return newim;
}

image gaussian_blur_r5(image im1){
	vector<vector<int> >kernel(5);
	
	kernel[0].push_back(1);kernel[0].push_back(4);kernel[0].push_back(6);kernel[0].push_back(4);kernel[0].push_back(1);
	kernel[1].push_back(4);kernel[1].push_back(16);kernel[1].push_back(24);kernel[1].push_back(16);kernel[1].push_back(4);
	kernel[2].push_back(6);kernel[2].push_back(24);kernel[2].push_back(36);kernel[2].push_back(24);kernel[2].push_back(6);
	kernel[3].push_back(4);kernel[3].push_back(16);kernel[3].push_back(24);kernel[3].push_back(16);kernel[3].push_back(4);
	kernel[4].push_back(1);kernel[4].push_back(4);kernel[4].push_back(6);kernel[4].push_back(4);kernel[4].push_back(1);
	
	image newim=convolution2D(im1,kernel,5,256);

	return newim;
}

image sharpen_high_pass(image im1){
	vector<vector<int> >kernel(3);
	kernel[0].push_back(-1);kernel[0].push_back(-1);kernel[0].push_back(-1);
	kernel[1].push_back(-1);kernel[1].push_back(9);kernel[1].push_back(-1);
	kernel[2].push_back(-1);kernel[2].push_back(-1);kernel[2].push_back(-1);
    //implement addition
	image newim=convolution2D(im1,kernel,3,9);

	//return addition(im1,newim);
	return newim;
}

image laplacian_edge_detection(image im1){
	vector<vector<int> >kernel(3);
	kernel[0].push_back(0);kernel[0].push_back(-1);kernel[0].push_back(0);
	kernel[1].push_back(-1);kernel[1].push_back(4);kernel[1].push_back(-1);
	kernel[2].push_back(0);kernel[2].push_back(-1);kernel[2].push_back(0);
    //normal edge detection done above is also laplacian 
	image newim=convolution2D(im1,kernel,3,1);

	return newim;
}


image arnold_encrypt(image im1, vector<int>key){
	//the encryption key consists of 5 numbers,1st is number of iterations and the next 4 are entries in 2x2 matrix which
	//used for linear transformation of the image;
	if(key.size()>5){
		exit(1);
	}
	image newim=im1;
	int iterations=key[0];
	int a,b,c,d;
	a=key[1];b=key[2];c=key[3];d=key[4];
	for(int i=1;i<=iterations;++i){
		for(int x=0;x<im1.rows;++x){
			for(int y=0;y<im1.columns;++y){
				int x_new=((a*x)+(b*y))%im1.rows;
				int y_new=((c*x)+(d*y))%im1.columns;
				newim.R[x_new][y_new]=im1.R[x][y];
				newim.G[x_new][y_new]=im1.G[x][y];
				newim.B[x_new][y_new]=im1.B[x][y];
			}
		}
	}

	return newim;

}

image arnold_decrypt(image im1, vector<int>key){
	//the  key consists of 5 numbers,1st is number of iterations and the next 4 are entries in 2x2 matrix which
	//used for linear transformation of the image;
	//same as encryption but the key is matrix is inverted in this case
	if(key.size()>5){
		exit(1);
	}
	swap(key[1],key[4]);
	key[2]=0-key[2];
	key[3]=0-key[3];
	image newim=im1;
	int iterations=key[0];
	int a,b,c,d;
	a=key[1];b=key[2];c=key[3];d=key[4];
	for(int i=1;i<=iterations;++i){
		for(int x=0;x<im1.rows;++x){
			for(int y=0;y<im1.columns;++y){
				int x_new=abs(((a*x)+(b*y))%im1.rows);
				int y_new=abs(((c*x)+(d*y))%im1.columns);
				newim.R[x_new][y_new]=im1.R[x][y];
				newim.G[x_new][y_new]=im1.G[x][y];
				newim.B[x_new][y_new]=im1.B[x][y];
			}
		}
	}

	return newim;

}






int main(){
	image im1,im2,im3,im4,im5,im6;
	im1=read_image();
	//dump_image(im1,"house1.txt");
	//im2=convert_to_grayscale(im1);
	//im3=otsu_binarize(im1);
	//im4=invert_colors(im1);
	im5=arnold_encrypt(im1,{120,21,62,73,94});
	im6=arnold_decrypt(im5,{120,21,62,73,94});
	//dump_image(im4,"houseinverted.txt");
	//dump_image(im2,"housegray.txt");
	//dump_image(im3,"housebinarize.txt");
	dump_image(im5,"mario_decrypt.txt");

	

	return 0;
}







