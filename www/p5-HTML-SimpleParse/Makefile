# $NetBSD: Makefile,v 1.31 2022/06/28 11:37:24 wiz Exp $

DISTNAME=	HTML-SimpleParse-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module implementing a bare-bones HTML parser

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTML/SimpleParse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
