#pragma once

#include <string>

namespace LogMessages
{
	// Info
	const std::string applicationStarted{ "Application Started" };
	const std::string loginSuccessful{ "Login Successful" };
	const std::string loggedOut{ "Logged Out" };
	const std::string clientAdded{ "Client Added Successfully" };
	const std::string clientUpdated{ "Client Updated Successfully" };
	const std::string clientDeleted{ "Client Deleted Successfully" };
	const std::string depositCompleted{ "Deposit Completed Successfully" };
	const std::string withdrawalCompleted{ "Withdrawal Completed Successfully" };
	const std::string userAdded{ "User Added Successfully" };
	const std::string userUpdated{ "User Updated Successfully" };
	const std::string userDeleted{ "User Deleted Successfully" };
	const std::string applicationClosed{ "Application Closed" };

	// Warning
	const std::string loginFailed{ "Login Failed" };
	const std::string clientNotFound{ "Client Not Found" };
	const std::string userNotFound{ "User Not Found" };
	const std::string insufficientBalance{ "Insufficient Balance" };
	const std::string invalidDepositAmount{ "Invalid Deposit Amount" };
	const std::string invalidWithdrawalAmount{ "Invalid Withdrawal Amount" };
	const std::string accessDenied{ "Access Denied" };
	const std::string operationCancelled{ "Operation Cancelled" };

	// Error
	const std::string failedToOpenClientsFile{ "Failed To Open Clients File" };
	const std::string failedToSaveClientsData{ "Failed To Save Clients Data" };
	const std::string failedToOpenUsersFile{ "Failed To Open Users File" };
	const std::string failedToSaveUsersData{ "Failed To Save Users Data" };
}