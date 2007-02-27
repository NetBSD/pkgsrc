# $NetBSD: Makefile,v 1.6 2007/02/27 14:12:05 wiz Exp $

DISTNAME=	HTTP-Cache-Transparent-0.7
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Cache-Transparent/
COMMENT=	Cache the result of http get-requests persistently

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/HTTP/Cache/Transparent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
