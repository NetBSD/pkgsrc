# $NetBSD: Makefile,v 1.6 2005/04/11 21:48:00 tv Exp $

DISTNAME=      	Kwiki-RecentChanges-0.13
PKGNAME=       	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki plugin to display recent changes

DEPENDS+=	p5-Kwiki>=0.37nb1:../../www/p5-Kwiki

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Kwiki/RecentChanges/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
