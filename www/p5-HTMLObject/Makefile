# $NetBSD: Makefile,v 1.26 2019/11/04 22:10:05 rillig Exp $

DISTNAME=	libhtmlobject-perl-${VERSION}
PKGNAME=	p5-HTMLObject-${VERSION}
PKGREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=htmlobject/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://htmlobject.sourceforge.net/
COMMENT=		Perl5 module to quickly and easily create Dynamic HTML pages
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-Data-FormValidator>=3.59:../../textproc/p5-Data-FormValidator

VERSION=	2.29

PERL5_PACKLIST=		auto/HTMLObject/.packlist

# strange garbage found (hope I am not wrong). mef@
post-patch:
	(cd ${WRKSRC}; ${RM}  ._Makefile.PL )

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
