# $NetBSD: Makefile,v 1.1.1.1 2004/12/26 21:51:18 jlam Exp $

DISTNAME=      	Kwiki-UserName-0.13
PKGNAME=       	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	module/by-module
AUTHOR_DIR=	authors/id/I/IN/INGY

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki user name plugin

DEPENDS+=	p5-Kwiki>=0.34:../../www/p5-Kwiki
DEPENDS+=	p5-Kwiki-UserPreferences>=0.12:../../www/p5-Kwiki-UserPreferences

USE_BUILDLINK3=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Kwiki/UserName/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
