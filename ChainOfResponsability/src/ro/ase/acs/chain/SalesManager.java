package ro.ase.acs.chain;

public class SalesManager extends CallCenterHandler {

	@Override
	public boolean refund(double suma) {
		if(suma < 5000) {
			System.out.println("Refund performed by sales manager!");
		    return true;	
		}
		else if(nextHandler != null) {
			return nextHandler.refund(suma);	
		}
		else {
			System.out.println("Refund cannot be done via call center!");
			return false;
		}
	}

}
