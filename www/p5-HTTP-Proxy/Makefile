# $NetBSD: Makefile,v 1.1 2006/03/23 17:59:33 christos Exp $
#

DISTNAME=	HTTP-Proxy-0.18
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hss
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Proxy/
COMMENT=	Perl5 module providing a simple HTTP proxy daemon

PERL5_PACKLIST=		auto/HTTP/Proxy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
