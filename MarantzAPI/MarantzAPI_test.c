#include <python2.7/Python.h>
#include <assert.h>

// This with my_test.py works!!
// Tested 29/7/2020 - it does work!!

//int Marantz_cmd (char* cmd, char* param){
int Marantz_cmd (char* class_IP, char* class_browser, char* cmd, char* param){
    //char* cmd1 = cmd;
    //char* param1 = param;
    //printf("Marantz_cmd called. cmd=%s, parameter=%s\n", cmd, param);
    
    setenv("PYTHONPATH", ".", 1);
    
    Py_Initialize();
    
    //PyObject* pModule = PyImport_ImportModule("MarantzAPI_test");  					// Import Python Module
    PyObject* pModule = PyImport_ImportModule("MarantzAPI");  							// Import Python Module 					// Import Python Module
    //PyObject* pModule = PyImport_ImportModule("/home/git/MarantzAPI/MarantzAPI/MarantzAPI");
    assert(pModule != NULL);
    
    PyObject* pIP = PyObject_GetAttrString(pModule, "IP");         					// Class name in module
    assert(pIP != NULL);
    
    //PyObject* parms = Py_BuildValue("iiss", 23, 1, "192.168.1.47", "firefox"); 	// Parameters for Method call: "int", "int", "string", "string"
    PyObject* parms = Py_BuildValue("iiss", 23, 1, class_IP, class_browser); 		// Parameters for Method call: "int", "int", "string", "string"
    assert(parms != NULL);
    
    PyObject* pavr = PyObject_CallObject(pIP, parms);      								//pavr = pIP( 23, 1, av_url="192.168.1.47", browser="firefox")
    assert(pavr != NULL);
    
    PyObject* pres = PyObject_CallMethod(pavr, cmd, "(s)", param);  					// Call Method with parameters                                                              
    //PyObject* presult2 = PyObject_CallMethod(pavr, "amp_assign", "(s)", "Front B");   //avr.amp_assign("Front B")   
    if (pres == NULL){
        PyErr_Print();
        Py_Finalize();
        return 0;
    }
    assert(pres != NULL);
    Py_DECREF(pModule);
    Py_DECREF(pIP);
    Py_DECREF(parms);
    Py_DECREF(pavr);
    Py_DECREF(pres);
    
    Py_Finalize();
    
    return 0;
}


int main(int argc, char **argv){
    
    printf ("Test Start\n\n");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PWON");
    
    printf ("Phase 1\n");
    
    Marantz_cmd("192.168.1.47", "firefox", "amp_assign", "Front B");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT SPA");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT?");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT SPB");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT?");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT A+B");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT?");
    
    printf ("Phase 2\n");

    Marantz_cmd("192.168.1.47", "firefox", "amp_assign", "ZONE2");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT SPA");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT?");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT SPB");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT?");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT A+B");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT?");

    printf ("Phase 3\n");

    Marantz_cmd("192.168.1.47", "firefox", "amp_assign", "Front B");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT SPA");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT?");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT SPB");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT?");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT A+B");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT?");   
	
	 printf ("Phase 4\n");
    
    Marantz_cmd("192.168.1.47", "firefox", "amp_assign", "Surround Back");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT?");
    
	 printf ("Phase 5\n");   
	  
    Marantz_cmd("192.168.1.47", "firefox", "amp_assign", "Bi-Amp");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT?");
    
	 printf ("Phase 6\n");    
    
    Marantz_cmd("192.168.1.47", "firefox", "amp_assign", "Front Height");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PSFRONT?");
   
	 printf ("Phase 7\n");   
     
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "PWSTANSBY");
    Marantz_cmd("192.168.1.47", "firefox", "write_command", "ZMOFF");
    
    printf ("Test End\n");
     //return 0;
    
    
}
    
