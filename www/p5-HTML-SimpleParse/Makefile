# $NetBSD: Makefile,v 1.7 2003/07/22 04:14:32 martti Exp $

DISTNAME=	HTML-SimpleParse-0.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hsp
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module implementing a bare-bones HTML parser

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/SimpleParse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
