# $NetBSD: Makefile,v 1.4 2002/09/25 14:53:05 seb Exp $

DISTNAME=	HTML-SimpleParse-0.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hsp
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module implementing a bare-bones HTML parser

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/SimpleParse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
