# $NetBSD: Makefile,v 1.13 2017/06/05 14:25:30 ryoon Exp $

DISTNAME=	Reaction-0.002005
PKGNAME=	p5-Reaction-0.2.5
PKGREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Reaction/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Reaction/
COMMENT=	Perl 5 extended MVC framework based on Catalyst

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Reaction/.packlist

REPLACE_PERL+=	script/moose_to_rclass.pl
REPLACE_PERL+=	script/rclass_back_to_moose.pl

DEPENDS+=	p5-Catalyst-Runtime>=5.80002:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-Component-ACCEPT_CONTEXT>=0.05:../../www/p5-Catalyst-Component-ACCEPT_CONTEXT
DEPENDS+=	p5-Catalyst-Component-InstancePerContext>=0.001001:../../www/p5-Catalyst-Component-InstancePerContext
DEPENDS+=	p5-Catalyst-Model-DBIC-Schema>=0.23:../../databases/p5-Catalyst-Model-DBIC-Schema
DEPENDS+=	p5-Catalyst-Plugin-ConfigLoader>=0.23:../../www/p5-Catalyst-Plugin-ConfigLoader
DEPENDS+=	p5-Catalyst-Plugin-I18N>=0.09:../../www/p5-Catalyst-Plugin-I18N
DEPENDS+=	p5-Catalyst-Plugin-Static-Simple>=0.21:../../www/p5-Catalyst-Plugin-Static-Simple
DEPENDS+=	p5-Catalyst-View-TT>=0.29:../../www/p5-Catalyst-View-TT
DEPENDS+=	p5-Config-General>=2.42:../../devel/p5-Config-General
DEPENDS+=	p5-Crypt-Eksblowfish>=0.005:../../security/p5-Crypt-Eksblowfish
DEPENDS+=	p5-DBIx-Class>=0.08100:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBIx-Class-IntrospectableM2M>=0.001001:../../databases/p5-DBIx-Class-IntrospectableM2M
DEPENDS+=	p5-DateTime>=0.47:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Event-Recurrence>=0.16:../../time/p5-DateTime-Event-Recurrence
DEPENDS+=	p5-DateTime-Set-[0-9]*:../../time/p5-DateTime-Set
DEPENDS+=	p5-Devel-Declare>=0.005000:../../devel/p5-Devel-Declare
DEPENDS+=	p5-Email-Valid>=0.181:../../mail/p5-Email-Valid
DEPENDS+=	p5-File-ShareDir>=1.00:../../devel/p5-File-ShareDir
DEPENDS+=	p5-PathTools>=3.29:../../devel/p5-PathTools
DEPENDS+=	p5-Moose>=2:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.10:../../devel/p5-MooseX-Types
DEPENDS+=	p5-MooseX-Types-URI>=0.02:../../devel/p5-MooseX-Types-URI
DEPENDS+=	p5-MooseX-Types-Common>=0.001000:../../devel/p5-MooseX-Types-Common
DEPENDS+=	p5-MooseX-Types-DateTime>=0.03:../../time/p5-MooseX-Types-DateTime
DEPENDS+=	p5-MooseX-MethodAttributes>=0.18:../../devel/p5-MooseX-MethodAttributes
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
DEPENDS+=	p5-Sub-Exporter>=0.982:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Sub-Name>=0.04:../../devel/p5-Sub-Name
DEPENDS+=	p5-Template-Toolkit>=2.20:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Time-modules>=2006.0814:../../time/p5-Time-modules
DEPENDS+=	p5-URI>=1.37:../../www/p5-URI
DEPENDS+=	p5-aliased>=0.22:../../devel/p5-aliased
DEPENDS+=	p5-namespace-clean>=0.11:../../devel/p5-namespace-clean
DEPENDS+=	p5-Method-Signatures-Simple>=0.03:../../devel/p5-Method-Signatures-Simple
DEPENDS+=	p5-signatures>=0.05:../../devel/p5-signatures
DEPENDS+=	p5-MooseX-Role-Parameterized>=0.24:../../devel/p5-MooseX-Role-Parameterized
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON

# For test target
BUILD_DEPENDS+=	p5-Test-Class>=0.31:../../devel/p5-Test-Class
BUILD_DEPENDS+=	p5-Test-WWW-Mechanize-Catalyst>=0.51:../../www/p5-Test-WWW-Mechanize-Catalyst
BUILD_DEPENDS+=	p5-Test-Memory-Cycle>=1.04:../../devel/p5-Test-Memory-Cycle
BUILD_DEPENDS+=	p5-SQL-Translator>=0.09004:../../databases/p5-SQL-Translator

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
