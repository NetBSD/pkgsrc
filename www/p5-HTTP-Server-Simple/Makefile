# $NetBSD: Makefile,v 1.1.1.1 2006/02/07 21:31:35 seb Exp $
#

DISTNAME=	HTTP-Server-Simple-0.17
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hss
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Server-Simple
COMMENT=	Perl5 module providing a simple standalone HTTP daemon

PERL5_PACKLIST=		auto/HTTP/Server/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
