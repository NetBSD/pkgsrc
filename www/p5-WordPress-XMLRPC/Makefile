# $NetBSD: Makefile,v 1.1.1.1 2009/02/23 20:57:49 imil Exp $
#

DISTNAME=		WordPress-XMLRPC-1.18
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www net
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/L/LE/LEOCHARRE/}

MAINTAINER=		imil@gcu.info
HOMEPAGE=		http://search.cpan.org/dist/WordPress-XMLRPC/
COMMENT=		Perl 5 API to WordPress XML-RPC services

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-SOAP-Lite>=0.71.08:../../net/p5-SOAP-Lite

PERL5_PACKLIST=		auto/WordPress/XMLRPC/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
