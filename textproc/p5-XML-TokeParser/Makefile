# $NetBSD: Makefile,v 1.3 2016/06/08 19:24:46 wiz Exp $

DISTNAME=	XML-TokeParser-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-TokeParser/TokeParser.pm
COMMENT=	Simplified interface to XML::Parser

DEPENDS+=	p5-XML-Parser>=2.44:../../textproc/p5-XML-Parser

PERL5_PACKLIST= auto/XML/TokeParser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
