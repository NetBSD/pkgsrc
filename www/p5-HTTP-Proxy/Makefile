# $NetBSD: Makefile,v 1.24 2019/08/11 13:24:46 wiz Exp $
#

DISTNAME=	HTTP-Proxy-0.304
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Proxy
COMMENT=	Perl5 module providing a simple HTTP proxy daemon
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww>=2.0:../../www/p5-libwww

PERL5_PACKLIST=		auto/HTTP/Proxy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
