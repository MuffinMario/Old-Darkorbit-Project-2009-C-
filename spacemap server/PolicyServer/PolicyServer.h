
#ifndef POLICYSERVER_H
#define POLICYSERVER_H
#include <iostream>
#include <boost\bind.hpp>
#include <boost\shared_ptr.hpp>
#include <boost\enable_shared_from_this.hpp>
#include "../common/Constants.h"
#include "../common/coutcolor.h"
#include "PolicyHandler.h"

typedef boost::asio::ip::tcp tcp_t;
class CPolicyServer
{
	boost::asio::io_context& io;
	tcp_t::acceptor m_acceptor;
	unsigned short	m_port;
public:
	/* default constructor: normal i/o service and a port where the server is running on */
	CPolicyServer(boost::asio::io_service& io_service, unsigned short& port) : io(io_service),m_acceptor(io_service,tcp_t::endpoint(tcp_t::v4(), port)) {
		m_port = port;
		start_accept();
	}
private:

	/* Accepts the start from an incoming connection */
	void start_accept();

	/* Accept handler for binding */
	void handle_accept(CPolicyHandler::tcppointer newconnection, const boost::system::error_code& err);

};
#endif