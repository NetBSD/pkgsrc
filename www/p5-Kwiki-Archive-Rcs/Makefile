# $NetBSD: Makefile,v 1.1.1.1 2004/12/26 21:46:37 jlam Exp $

DISTNAME=      	Kwiki-Archive-Rcs-0.13
PKGNAME=       	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	module/by-module
AUTHOR_DIR=	authors/id/I/IN/INGY

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki page archive using RCS

DEPENDS+=	p5-Kwiki>=0.35:../../www/p5-Kwiki

USE_BUILDLINK3=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Kwiki/Archive/RCS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
