# $NetBSD: Makefile,v 1.9 2002/12/12 14:36:30 abs Exp $

DISTNAME=		HTML-Template-2.6
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5htm
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/} \
			${MASTER_SITE_SOURCEFORGE:=html-template/}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://html-template.sourceforge.net/
COMMENT=		perl5 module to create HTML templates with simple tags

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Template/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
