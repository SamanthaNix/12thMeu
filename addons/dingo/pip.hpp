class RenderTargets /// class for all Picture-in-Picture (PiP)
{
	class ForwardView
	{
		renderTarget = "rendertarget0"; /// Forward PIP
		class CameraView1
		{
			pointPosition		= "PIP0_POS"; 	/// memory point of PiP origin
			pointDirection		= "PIP0_DIR"; 	/// memory point of PiP DIRection
			renderQuality 		= 2;			/// what quality should the PiP be
			renderVisionMode 	= 0;			/// zero means standard vision
			fov 				= 0.85;			/// what is the angle of the PiP field of view
		}; 			
	};
	class RearView
	{
		renderTarget = "rendertarget1"; /// Reverse PIP
		class CameraView1
		{
			pointPosition		= "PIP1_POS"; 	/// memory point of PiP origin
			pointDirection		= "PIP1_DIR"; 	/// memory point of PiP DIRection
			renderQuality 		= 2;			/// what quality should the PiP be
			renderVisionMode 	= 0;			/// zero means standard vision
			fov 				= 0.85;			/// what is the angle of the PiP field of view
		}; 			
	};
	class LeftWing	/// rendering of PiPs is shared, it is best to have one for all sources, this is just an example
	{
		renderTarget = "rendertarget2";/// Left Wing PIP #(argb,512,512,1)r2t(rendertarget2,1.0)
		class CameraView1
		{
			pointPosition		= "PIP2_POS";
			pointDirection		= "PIP2_DIR";
			renderQuality 		= 2;
			renderVisionMode 	= 0;
			fov 				= 0.6;					
		};
	};
	class RightWing
	{
		renderTarget = "rendertarget3"; /// Right Wing PIP
		class CameraView1
		{
			pointPosition		= "PIP3_POS";
			pointDirection		= "PIP3_DIR";
			renderQuality 		= 2;
			renderVisionMode 	= 0;
			fov 				= 0.6;					
		}; 			
	};			
};
