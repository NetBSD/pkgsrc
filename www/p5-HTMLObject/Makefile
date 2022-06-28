# $NetBSD: Makefile,v 1.32 2022/06/28 11:37:26 wiz Exp $

VERSION=	2.30
DISTNAME=	libhtmlobject-perl-${VERSION}
PKGNAME=	p5-HTMLObject-${VERSION}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=htmlobject/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://htmlobject.sourceforge.net/
COMMENT=		Perl5 module to quickly and easily create Dynamic HTML pages
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-Data-FormValidator>=3.59:../../textproc/p5-Data-FormValidator

PERL5_PACKLIST=		auto/HTMLObject/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
