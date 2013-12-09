# $NetBSD: Makefile,v 1.13 2013/12/09 14:17:55 obache Exp $

DISTNAME=	Handel-1.00011
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CL/CLACO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://handelframework.com/
#HOMEPAGE=	http://search.cpan.org/dist/Handel/
COMMENT=	Simple commerce framework with AxKit/TT/Catalyst support

DEPENDS+=	p5-DBIx-Class>=0.08008:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBIx-Class-UUIDColumns>=0.02000:../../databases/p5-DBIx-Class-UUIDColumns
DEPENDS+=	p5-DBIx-Class-Validation>=0.02000:../../databases/p5-DBIx-Class-Validation
DEPENDS+=	p5-Data-Currency>=0.04002:../../finance/p5-Data-Currency
DEPENDS+=	p5-Class-Accessor-Grouped>=0.03:../../devel/p5-Class-Accessor-Grouped
DEPENDS+=	p5-Class-ISA>=0:../../devel/p5-Class-ISA
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Clone>=0.28:../../devel/p5-Clone
DEPENDS+=	{perl>=5.10.0,p5-Locale-Maketext>=1.06}:../../misc/p5-Locale-Maketext
DEPENDS+=	{perl>=5.10,p5-Module-Pluggable>=3.1}:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Module-Starter>=1.42:../../devel/p5-Module-Starter
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=0}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-DateTime>=0:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-MySQL>=0:../../time/p5-DateTime-Format-MySQL
DEPENDS+=	{perl>=5.13.1,p5-Locale-Codes>=2.07}:../../misc/p5-Locale-Codes
DEPENDS+=	p5-Locale-Currency-Format>=1.22:../../finance/p5-Locale-Currency-Format
DEPENDS+=	p5-FormValidator-Simple>=0.17:../../textproc/p5-FormValidator-Simple
DEPENDS+=	p5-Finance-Currency-Convert-WebserviceX>=0.03:../../finance/p5-Finance-Currency-Convert-WebserviceX
DEPENDS+=	{perl>=5.10,p5-NEXT>=0}:../../devel/p5-NEXT
DEPENDS+=	{perl>=5.10,p5-PathTools>=0}:../../devel/p5-PathTools
DEPENDS+=	p5-SQL-Translator>=0.08:../../databases/p5-SQL-Translator
DEPENDS+=	p5-DBD-SQLite>=0:../../databases/p5-DBD-SQLite

# Catalyst Support
DEPENDS+=	p5-Catalyst-Runtime>=5.7007:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-Devel>=1.02:../../www/p5-Catalyst-Devel
DEPENDS+=	p5-Catalyst-View-TT>=0:../../www/p5-Catalyst-View-TT
DEPENDS+=	p5-Catalyst-Plugin-Session>=0:../../www/p5-Catalyst-Plugin-Session
DEPENDS+=	p5-Catalyst-Plugin-Session-Store-File>=0:../../www/p5-Catalyst-Plugin-Session-Store-File
DEPENDS+=	p5-Catalyst-Plugin-Session-State-Cookie>=0:../../www/p5-Catalyst-Plugin-Session-State-Cookie
DEPENDS+=	p5-YAML>=0:../../textproc/p5-YAML
DEPENDS+=	p5-HTML-FillInForm>=0:../../www/p5-HTML-FillInForm

# Skip AxKit Support

USE_LANGUAGES=		# empty
PERL5_PACKLIST= 	auto/Handel/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
