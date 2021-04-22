package ro.ase.acs.chain;

public abstract class CallCenterHandler {

	protected CallCenterHandler nextHandler = null;

	/*public CallCenterHandler getNextHandler() {
		return nextHandler;
	}*/

	public void setNextHandler(CallCenterHandler nextHandler) {
		this.nextHandler = nextHandler;
	}

	public abstract boolean refund(double suma); 
	
}
