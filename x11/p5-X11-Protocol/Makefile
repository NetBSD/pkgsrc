# $NetBSD: Makefile,v 1.2 2004/12/20 11:31:14 grant Exp $
#

DISTNAME=		X11-Protocol-0.53
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		x11 perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=X11/}

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://search.cpan.org/dist/X11-Protocol/
COMMENT=		Interface to the X11 protocol

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/X11/Protocol/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
