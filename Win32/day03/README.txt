һ ����ע��ʹ���

  1 Win32���ڳ��򴴽�����
  
    1.1 WinMain��ں����Ķ���
    1.2 WindowProc�����Ķ���
    1.3 ע�ᴰ����
      RegisterClass/RegisterClassEx
    1.4 ��������
      CreateWindow/CreateWindowEx
    1.5 ���ڵ���ʾ��ˢ��
      ShowWindow/UpdateWindow
    1.6 ��Ϣ����
      GetMessage/DispatchMessage
    1.7 �����˳�
      WM_DESTROY/PostQuitMessage
      
  2 ���ڵ�ע��
  	
  	2.1 ������ķ���
  	  2.1.1 ϵͳȫ�ֵĴ�����.���簴ť("BUTTON")��
  	    �ı��༭��("EDIT")�ȡ�
  	  2.1.2 Ӧ�ó����ȫ�ִ����ࡣ������һ��Ӧ��
  	    ������EXE��DLL������ģ����ʹ�õĴ����ࡣ
  	  2.1.3 �ֲ������ࡣֻ���ڱ�ģ����ʹ�õ�
  	    �����ࡣ
  	    
  	2.2 ʵ�ִ������ע��
  	  2.2.1 ϵͳȫ�ֵĴ����࣬����ע��ֱ��ʹ�á�
  			ʹ��CreateWindow��������CLASSNAME��ָ��
  			ϵͳ�Ѿ�����õĴ����������Ƽ��ɡ�
  	  2.2.2 Ӧ�ó����ȫ�ִ�����,��Ҫ�ô���ʵ��
  	    ע�ᣬ��ע��ʱ��Ҫ����CS_GLOBALCLASS���塣
  	    ʵ�ַ�ʽ��
  	       WNDCLASS wc = {0};
  	       wc.style = CS_GLOBALCLASS|CS_HREDRAW..;
  	       ....
  	       RegisterClass( &wc );
  	  2.2.3 �ֲ������࣬��������CS_GLOBALCLASS���塣
  			ʹ��RegisterClass��RegisterClassExע��
				typedef struct _WNDCLASSEX { 
    				UINT    cbSize; //�ṹ��Ĵ�С
					  UINT    style; 
					  WNDPROC lpfnWndProc; 
					  int     cbClsExtra; 
					  int     cbWndExtra; 
					  HANDLE  hInstance; 
					  HICON   hIcon; 
					  HCURSOR hCursor; 
					  HBRUSH  hbrBackground; 
					  LPCTSTR lpszMenuName; 
					  LPCTSTR lpszClassName; 
					  HICON   hIconSm; //Сͼ��
					} WNDCLASSEX; 
				2.2.4 ��������
				   CS_HREDRAW ����ˮƽ�仯�����»��ƴ��ڡ�
				   CS_VREDRAW ���ڴ�ֱ�仯�����»��ƴ��ڡ�
				   CS_DBCLICK ���ڿ��Խ������˫����Ϣ
				   CS_GLOBALCLASS ����Ӧ�ó���ȫ�ִ����ࡣ
				   CS_BYTEALIGNWINDOW ���ڶ��뷽ʽ,��8�ı�������
				   CS_BYTEALIGNCLIENT ���ڿͻ������뷽ʽ,��8�ı�������
				   CS_CLASSDC �����������͵Ĵ���ʹ��ͬһ��DC(�豸������,��ͼʹ��)
				   CS_OWNDC ÿ������ӵ���Լ���DC
				   CS_PARENTDC ʹ�ø����ڵ�DC
				   CS_SAVEBITS ����λͼ���洰�ڽ���,�������
				           ���ڽ����ˢ������
				   CS_NOCLOSE ��ֹ�ر�����.
				
				2.2.5 ������ĸ������� cbClsExtra
				  �ڴ������������Ϣ������Լ���Ϣ.
				   cbClsExtra ���������Ϣ���ڴ�Ĵ�С
				   SetClassLong ����Ϣ���浽�ڴ���
				   GetClassLong ����Ϣ���ڴ���ȡ��
				     DWORD SetClassLong(
							  HWND hWnd,//���ڵľ��
							  int nIndex, //ֵ��������
							  LONG dwNewLong   //ֵ
							);
						 DWORD GetClassLong(
							  HWND hWnd,//���ڵľ��
							  int nIndex, //ֵ��������
							);
					cbClsExtra�ĳ���һ����4�ֽڵı���
				2.2.6 ���ڸ������� cbWndExtra
				   �ڴ��ڵ�������Ϣ������Լ���Ϣ.
  	      cbWndExtra ���������Ϣ���ڴ�Ĵ�С
  	      SetWindowLong ����Ϣ���浽�ڴ���
  	      GetWindowLong ����Ϣ���ڴ���ȡ��
  	
  	2.3 ���������غ���
  		RegisterClass/RegisterClassEx ע��
  	  UnregisterClass ע��
  	  GetClassInfo/GetClassInfoEx ��ȡ��Ϣ
  	  GetClassName ��ȡ���ڵĴ���������
  	  GetClassLong/SetClassLong �����฽�����ݵ����úͻ�ȡ
  	  GetWindowLong/SetWindowLong ���ڵĸ������ݵ����úͻ�ȡ
  	
    2.4 ��������ʱ��ζ�λ������
    
      2.4.1 ����Ӧ�ó���ֲ��Ĵ����ࡣ����ҵ���
            ִ��2.4.2������ִ��2.4.3
      2.4.2 ����ҵ�����һ�µĴ����࣬��Ƚ�
            HISNTANCE����������ȣ���ʹ���ҵ�
            �Ĵ�������Ϣ�������ڣ������ͬ������
            ���ң�ִ��2.4.3��
      2.4.3 ���δ�ҵ�����һ�µĴ����࣬�����
            ��Ӧ�ó���ȫ�ִ������в��ҡ�����ҵ���
            ִ��2.4.4������ִ��2.4.5
      2.4.4 ȫ�ִ������ҵ�һ�µģ�ʹ���ҵ�
            �Ĵ�������Ϣ�������ڡ�
      2.4.5 ϵͳȫ�ִ������в��ҡ�����ҵ�������
            ���ڣ����򷵻�ʧ�ܡ�
 
  3 ���ڴ���
   
    3.1 ���ڴ�������
      CreateWindow/CreateWindowEx
      HWND CreateWindowEx(
				  DWORD dwExStyle,//���ڵ���չ��ʽ
				  LPCTSTR lpClassName,  // pointer to registered class name
				  LPCTSTR lpWindowName, // pointer to window name
				  DWORD dwStyle,        // window style
				  int x,                // horizontal position of window
				  int y,                // vertical position of window
				  int nWidth,           // window width
				  int nHeight,          // window height
				  HWND hWndParent,      // handle to parent or owner window
				  HMENU hMenu,          // handle to menu, or child-window identifier
				  HINSTANCE hInstance,  // handle to application instance
				  LPVOID lpParam );     // pointer to window-creation data
		 3.2 ���ڷ�����չ���
		 
		    ���ڷ��: WS_XXXX����ķ��,�Ǵ��ڵ�
		        �������.
		    ��չ���: WS_EX_XXXXX ����ķ��,�Ǵ���
		        ����չ���.����: ToolWindow���ڵȵ�.
		    ��CreateWindow����ʹ�û������ڷ��,��չ
		    �Ĵ��ڷ��,��Ҫʹ��CreateWindowEx����.
		    
		    WS_OVERLAPPED����,���ʽ����
		    WS_POPUP����,����ʽ����
		    WS_CHILD����,�Ӵ���
		    
     3.3 �����ں��Ӵ���
        3.3.1 CreateWindowʱ,ָ��������
        3.3.2 �����ڵķ������WS_CHILD
        3.3.3 ����ʹ��SetParent��GetParent
           �������úͻ�ȡָ�����ڵĸ�����.
           
        ����: MoveWindow �ƶ�����.
        
     3.4 MDI���ڵĴ���
        3.4.1 ����������
           ע������������,����������.
						HWND hWnd = CreateWindowEx( 0,
							pszClassName, "MainWnd", 
							WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
							CW_USEDEFAULT, CW_USEDEFAULT,
							CW_USEDEFAULT, NULL, NULL, g_hInst,
							NULL );
        3.4.2 MDICLIENT����
        		1 ���CLIENTCREATESTRUCT�ṹ,��Ϊ��������
						CLIENTCREATESTRUCT cs = { 0 };
						cs.idFirstChild = 1000;//MDI��һ���Ӵ��ڵ�ID
						2 ����ʱ,ʹ��"MDICLIENT"��������.
						3 ���ĸ�������������
						HWND hWnd = CreateWindowEx( 0,
							"MDICLIENT", "MainWnd", 
							WS_CHILD|WS_VISIBLE, CW_USEDEFAULT,
							CW_USEDEFAULT, CW_USEDEFAULT,
							CW_USEDEFAULT, hParent, NULL, g_hInst,
							&cs );
        3.4.3 ����һ��MDI�Ӵ���
            1 ע������������,�����Ӵ���
            2 ���ĸ�����ΪMDICLIENT����
            3 ����WS_EX_MDICHILD�ķ��
					  HWND hWnd = 
					  CreateWindowEx( WS_EX_MDICHILD,
						pszClassName, "ChildWnd", 
						WS_CHILD|WS_VISIBLE, CW_USEDEFAULT,
						CW_USEDEFAULT, CW_USEDEFAULT,
						CW_USEDEFAULT, hParent, NULL, 
						g_hInst, NULL );
