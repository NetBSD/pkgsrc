# $NetBSD: Makefile,v 1.3 2005/02/02 17:29:08 jlam Exp $

DISTNAME=      	Kwiki-UserPreferences-0.13
PKGNAME=       	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki user preferences plugin

DEPENDS+=	p5-Kwiki>=0.37nb1:../../www/p5-Kwiki

USE_BUILDLINK3=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Kwiki/UserPreferences/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
