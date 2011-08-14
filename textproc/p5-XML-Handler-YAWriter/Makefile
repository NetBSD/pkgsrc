# $NetBSD: Makefile,v 1.12 2011/08/14 15:14:18 obache Exp $
#

DISTNAME=	XML-Handler-YAWriter-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
SVR4_PKGNAME=	p5xhy
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Handler-YAWriter/
COMMENT=	Another Perl module for writing XML documents

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

# really: XML::Parser::PerlSAX' => 0.06
DEPENDS+=		p5-libxml>=0.07:../../textproc/p5-libxml

PERL5_PACKLIST=		auto/XML/Handler/YAWriter/.packlist
REPLACE_PERL=		xmlpretty

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
