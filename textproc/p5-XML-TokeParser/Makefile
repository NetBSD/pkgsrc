# $NetBSD: Makefile,v 1.5 2018/08/22 09:47:09 wiz Exp $

DISTNAME=	XML-TokeParser-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-TokeParser/TokeParser.pm
COMMENT=	Simplified interface to XML::Parser

DEPENDS+=	p5-XML-Parser>=2.44:../../textproc/p5-XML-Parser

PERL5_PACKLIST= auto/XML/TokeParser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
