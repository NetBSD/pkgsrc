# $NetBSD: Makefile,v 1.7 2003/07/22 04:14:30 martti Exp $

DISTNAME=	HTML-Clean-0.8
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hcl
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module that cleans up HTML code for web browsers

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Clean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
