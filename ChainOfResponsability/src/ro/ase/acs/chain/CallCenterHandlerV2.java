package ro.ase.acs.chain;

public interface CallCenterHandlerV2 {

	public CallCenterHandlerV2 getNextHandler();
		
	public void setNextHandler(CallCenterHandlerV2 nextHandler);
		
	public boolean refund(double suma);
	
}
