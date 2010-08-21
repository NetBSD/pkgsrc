# $NetBSD: Makefile,v 1.2 2010/08/21 16:36:19 seb Exp $
#

.include "../../textproc/cabocha/Makefile.common"

PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1

COMMENT=	CaboCha perl module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++

CONFIGURE_DIRS=	perl

PERL5_PACKLIST=		auto/CaboCha/.packlist

BUILDLINK_API_DEPENDS.cabocha+=	cabocha>=${PKGVERSION_NOREV}
.include "../../textproc/cabocha/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
