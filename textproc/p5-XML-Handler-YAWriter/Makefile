# $NetBSD: Makefile,v 1.6 2006/01/24 07:32:37 wiz Exp $
#

DISTNAME=	XML-Handler-YAWriter-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5xhy
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Handler-YAWriter/
COMMENT=	Another Perl module for writing XML documents

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# really: XML::Parser::PerlSAX' => 0.06
DEPENDS+=		p5-libxml>=0.07:../../textproc/p5-libxml

PERL5_PACKLIST=		auto/XML/Handler/YAWriter/.packlist
REPLACE_PERL=		xmlpretty

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
