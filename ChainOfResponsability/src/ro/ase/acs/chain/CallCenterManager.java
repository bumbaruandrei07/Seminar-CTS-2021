package ro.ase.acs.chain;

public class CallCenterManager extends CallCenterHandler {

	@Override
	public boolean refund(double suma) {
		if(suma < 500) {
			System.out.println("Refund performed by call center manager");
		    return true;	
		}
		else if(nextHandler != null) {
			return nextHandler.refund(suma);	
		}
		else {
			System.out.println("Refund not possible!");
			return false;
		}
	}
}
