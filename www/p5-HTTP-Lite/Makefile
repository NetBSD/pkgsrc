# $NetBSD: Makefile,v 1.7 2011/08/14 16:05:57 obache Exp $

DISTNAME=		HTTP-Lite-2.2
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5hl
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTTP-Lite/
COMMENT=		Lightweight HTTP client implementation
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/HTTP/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
