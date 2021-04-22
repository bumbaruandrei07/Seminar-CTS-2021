package ro.ase.acs.main;

import ro.ase.acs.chain.CallCenterHandler;
import ro.ase.acs.chain.CallCenterManager;
import ro.ase.acs.chain.CallCenterOperator;
import ro.ase.acs.chain.SalesManager;

public class Main {

	public static void main(String[] args) {

		CallCenterHandler operator = new CallCenterOperator();
		CallCenterHandler manager = new CallCenterManager();
		CallCenterHandler salesManager =  new SalesManager();
		
		operator.setNextHandler(manager);
		manager.setNextHandler(salesManager);
		
		operator.refund(60);
		operator.refund(160);
		operator.refund(2000);
		operator.refund(7000);
	}

}
