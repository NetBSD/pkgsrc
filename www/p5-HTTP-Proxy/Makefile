# $NetBSD: Makefile,v 1.14 2013/05/31 12:42:44 wiz Exp $
#

DISTNAME=	HTTP-Proxy-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Proxy/
COMMENT=	Perl5 module providing a simple HTTP proxy daemon
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww>=2.0:../../www/p5-libwww

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTTP/Proxy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
