# $NetBSD: Makefile,v 1.2 2004/12/26 23:21:43 jlam Exp $

DISTNAME=      	Kwiki-Search-0.12
PKGNAME=       	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki search plugin

DEPENDS+=	p5-Kwiki>=0.34:../../www/p5-Kwiki

USE_BUILDLINK3=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Kwiki/Search/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
