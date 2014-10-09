# $NetBSD: Makefile,v 1.18 2014/10/09 14:07:11 wiz Exp $

DISTNAME=		libhtmlobject-perl-${VERSION}
PKGNAME=		p5-HTMLObject-${VERSION}
PKGREVISION=		6
CATEGORIES=		www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=htmlobject/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://htmlobject.sourceforge.net/
COMMENT=		Perl5 module to quickly and easily create Dynamic HTML pages

DEPENDS+=	p5-Data-FormValidator>=3.59:../../textproc/p5-Data-FormValidator

VERSION=	2.28

PERL5_PACKLIST=		auto/HTMLObject/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
