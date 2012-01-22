# $NetBSD: Makefile,v 1.4 2012/01/22 20:14:03 abs Exp $

DISTNAME=	Task-Plack-0.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Task/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Task-Plack/
COMMENT=	Perl 5 Plack bundle
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Task/Plack/.packlist

DEPENDS+= p5-CGI-Application-PSGI>=1.00:../../www/p5-CGI-Application-PSGI
DEPENDS+= p5-CGI-Compile>=0.12:../../www/p5-CGI-Compile
DEPENDS+= p5-CGI-Emulate-PSGI>=0.10:../../www/p5-CGI-Emulate-PSGI
DEPENDS+= p5-CGI-PSGI>=0.11:../../www/p5-CGI-PSGI
DEPENDS+= p5-Catalyst-Engine-PSGI>=0.11:../../www/p5-Catalyst-Engine-PSGI
DEPENDS+= p5-Corona>=0.1004:../../www/p5-Corona
DEPENDS+= p5-Devel-StackTrace-WithLexicals>=0.06:../../devel/p5-Devel-StackTrace-WithLexicals
DEPENDS+= p5-FCGI>=0.71:../../www/p5-FCGI
DEPENDS+= p5-FCGI-Client>=0.04:../../www/p5-FCGI-Client
DEPENDS+= p5-FCGI-ProcManager>=0.19:../../www/p5-FCGI-ProcManager
DEPENDS+= p5-HTTP-Server-Simple-PSGI>=0.14:../../www/p5-HTTP-Server-Simple-PSGI
DEPENDS+= p5-IO-Handle-Util>=0.01:../../devel/p5-IO-Handle-Util
DEPENDS+= p5-Net-FastCGI>=0.12:../../www/p5-Net-FastCGI
DEPENDS+= p5-PSGI>=1.03:../../www/p5-PSGI
DEPENDS+= p5-Plack>=0.9945:../../www/p5-Plack
DEPENDS+= p5-Plack-App-Proxy>=0.15:../../www/p5-Plack-App-Proxy
DEPENDS+= p5-Plack-Handler-AnyEvent-HTTPD>=0.01:../../www/p5-Plack-Handler-AnyEvent-HTTPD
DEPENDS+= p5-Plack-Handler-AnyEvent-ReverseHTTP>=0.04:../../www/p5-Plack-Handler-AnyEvent-ReverseHTTP
DEPENDS+= p5-Plack-Handler-AnyEvent-SCGI>=0.02:../../www/p5-Plack-Handler-AnyEvent-SCGI
DEPENDS+= p5-Plack-Handler-SCGI>=0.02:../../www/p5-Plack-Handler-SCGI
DEPENDS+= p5-Plack-Middleware-Auth-Digest>=0.03:../../www/p5-Plack-Middleware-Auth-Digest
DEPENDS+= p5-Plack-Middleware-ConsoleLogger>=0.02:../../www/p5-Plack-Middleware-ConsoleLogger
DEPENDS+= p5-Plack-Middleware-Debug>=0.09:../../www/p5-Plack-Middleware-Debug
DEPENDS+= p5-Plack-Middleware-Deflater>=.0.3:../../www/p5-Plack-Middleware-Deflater
DEPENDS+= p5-Plack-Middleware-File-Sass>=.0.1:../../www/p5-Plack-Middleware-File-Sass
DEPENDS+= p5-Plack-Middleware-Header>=0.03:../../www/p5-Plack-Middleware-Header
DEPENDS+= p5-Plack-Middleware-JSConcat>=0.29:../../www/p5-Plack-Middleware-JSConcat
DEPENDS+= p5-Plack-Middleware-ReverseProxy>=0.06:../../www/p5-Plack-Middleware-ReverseProxy
DEPENDS+= p5-Plack-Middleware-Session>=0.12:../../www/p5-Plack-Middleware-Session
DEPENDS+= p5-Squatting-On-PSGI>=0.04:../../www/p5-Squatting-On-PSGI
DEPENDS+= p5-Starlet>=0.10:../../www/p5-Starlet
DEPENDS+= p5-Starman>=0.2006:../../www/p5-Starman
DEPENDS+= p5-Test-WWW-Mechanize-PSGI>=0.35:../../www/p5-Test-WWW-Mechanize-PSGI
DEPENDS+= p5-Twiggy>=0.1006:../../www/p5-Twiggy

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
