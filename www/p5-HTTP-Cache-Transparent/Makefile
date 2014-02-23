# $NetBSD: Makefile,v 1.15 2014/02/23 13:19:54 wen Exp $

DISTNAME=	HTTP-Cache-Transparent-1.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Cache-Transparent/
COMMENT=	Cache the result of http get-requests persistently
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/HTTP/Cache/Transparent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
