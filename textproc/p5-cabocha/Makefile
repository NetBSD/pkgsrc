# $NetBSD: Makefile,v 1.1.1.1 2010/05/19 12:35:26 obache Exp $
#

.include "../../textproc/cabocha/Makefile.common"

PKGNAME=	p5-${DISTNAME}

COMMENT=	CaboCha perl module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++

CONFIGURE_DIRS=	perl

PERL5_PACKLIST=		auto/CaboCha/.packlist

BUILDLINK_API_DEPENDS.cabocha+=	cabocha>=${PKGVERSION_NOREV}
.include "../../textproc/cabocha/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
