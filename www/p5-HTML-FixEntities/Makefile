# $NetBSD: Makefile,v 1.19 2013/05/31 12:42:41 wiz Exp $

DISTNAME=		HTML-FixEntities-1.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		www perl5
MASTER_SITES=		http://www.mono.org/abs/tools/HTML-FixEntities/

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://www.mono.org/abs/tools/HTML-FixEntities/
COMMENT=		Perl5 module to convert latin1 to equivalent HTML

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTML/FixEntities/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
