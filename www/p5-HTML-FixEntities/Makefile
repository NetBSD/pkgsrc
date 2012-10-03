# $NetBSD: Makefile,v 1.17 2012/10/03 21:58:43 wiz Exp $

DISTNAME=		HTML-FixEntities-1.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		www perl5
MASTER_SITES=		http://www.mono.org/abs/tools/HTML-FixEntities/

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://www.mono.org/abs/tools/HTML-FixEntities/
COMMENT=		Perl5 module to convert latin1 to equivalent HTML

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/HTML/FixEntities/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
