# $NetBSD: Makefile,v 1.4 2011/08/14 16:05:56 obache Exp $

DISTNAME=	HTTP-Async-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Async/
COMMENT=	Lightweight HTTP client implementation

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/HTTP/Async/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
